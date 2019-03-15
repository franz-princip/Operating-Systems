import java.io.*;
import java.net.*;

class EchoServer {
    
    public static void main(String args[]) {
        //Try to create a Server Socket running on port number 4545
        try(ServerSocket sc = new ServerSocket(4545);
        ){
            System.out.println("Server is Ready and waiting for clients");
            while (true) {//endless loop 
                Socket cl = sc.accept();//Accept a client connection
                System.out.println("Client Is Connected");
                //Get the stream which can be used to output the data to client process
                ObjectOutputStream op = new ObjectOutputStream(cl.getOutputStream());
                //Get the Stream which can be used to get the input from Client process
                ObjectInputStream ip = new ObjectInputStream(cl.getInputStream());
                String str = "";//A variable to store the messages received from client
                while (true) {
                    str = (String) (ip.readObject());//read the message from client
                    if (str == null) {//check if the message is null, indicating that connection is closed
                        System.out.println("Client Disconnected");
                        cl.close();//Close the Socket connected to client and break loop
                        break;
                    }
                    op.writeObject(str);//If the client is still connected, send back the message received
                    op.flush();//Flush the output stream connected to this socket
                }
            }
        }
        catch (IOException | ClassNotFoundException e) {
            System.out.println(e);//Show the exception for IOEsception or ClassNotFoundException
        }
    }
}
