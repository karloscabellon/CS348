import java.io.*;
import java.net.*;

public class TCPServer {
public static void main(String args[]) {
    try {
        int serverPort = 7896;
        ServerSocket listenSocket = new ServerSocket(serverPort);

    while(true) {
        System.out.println("Waiting for a client ....");
        Socket clientSocket = listenSocket.accept();
        System.out.println("Connection received from " +
        clientSocket.getInetAddress().getHostName());
        // start a new thread
        ClientThread c = new ClientThread(clientSocket);
    }
}
    catch (IOException e) {
        System.err.println("Error in connection " + e.getMessage());
        System.exit(0);
        }
    }
}

