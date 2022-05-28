import java.io.*;
import java.net.*;
import java.util.*;


public class TCPClient {
    public static void main(String args[]){

        try (Socket sock = new Socket("localhost", 7896);Scanner c = new Scanner(System.in)){
            String s;
            String modstring;
            ObjectOutputStream out_client = new ObjectOutputStream(sock.getOutputStream());
            ObjectInputStream in_server = new ObjectInputStream(sock.getInputStream());

            System.out.print("Enter Client Request: ");
            s = c.nextLine();
            out_client.writeObject(s+'\n');
            modstring = (String) in_server.readObject();
            System.out.println(modstring);
            sock.close();
        }catch(Exception e){
            System.out.println(e);
        }
    }
}