import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.net.Socket;

public class ClientThread extends Thread {
    ObjectOutputStream out = null;
    ObjectInputStream in = null;
    Socket clientSocket;
public ClientThread(Socket ClientSocket) {
    try {
        clientSocket = ClientSocket;
        out = new ObjectOutputStream(clientSocket.getOutputStream() );
        in = new ObjectInputStream(clientSocket.getInputStream());
        this.start(); // call run()
        }
    catch (IOException e) {
        System.err.println("Error 1 in connection " + e );
        System.exit(0);
    }
}
public void run() {
    // Assumes client sends a string, receives a string response
    // then quits
    String lineIn = "";
    try {
        // must cast from Object to String
        lineIn = (String) in.readObject();
        System.out.println( "Received from " + clientSocket.getInetAddress().getHostName() +": " + lineIn );
        // important to create a new object in this case a String
        out.writeObject(new String("From Server: " + lineIn.toLowerCase()));
    }
    catch (ClassNotFoundException e) {
        System.err.println("Class not found " + e);
        System.exit(0);
    }
    catch (IOException e2) {
        System.err.println("Error in I/O " + e2);
        System.exit(0);
    }
    // close client
    try {
        in.close();
        out.close();
        clientSocket.close();
        System.out.println("Connection closed from " + clientSocket.getInetAddress().getHostName());
    }
    catch (IOException e3) {
        System.err.println("Error 2 in connection " + e3);
        System.exit(0);
        }
    }
}