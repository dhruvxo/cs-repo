import threading
import socket
import queue

host = '127.0.0.1'
port = 59000
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((host, port))
server.listen()

clients = []
aliases = []
blocked_clients = []

client_priority = {}  # Dictionary to store client priority levels
message_queue = queue.PriorityQueue()  # Priority queue for storing messages

def broadcast(message):
    for client in clients:
        client.send(message)

def handle_client(client):
    while True:
        try:
            message = client.recv(1024)
            if client in blocked_clients:
                client.send("You are blocked and cannot send messages.".encode('utf-8'))
                break  # Exit the loop for blocked clients
            else:
                priority = client_priority[client]
                message_queue.put((priority, message))  # Add message to the priority queue
        except:
            index = clients.index(client)
            clients.remove(client)
            client.close()
            alias = aliases[index]
            aliases.remove(alias)
            if client in blocked_clients:
                blocked_clients.remove(client)
            broadcast(f'{alias} has left the chat room!'.encode('utf-8'))
            break

def block_client(client):
    blocked_clients.append(client)
    client.send("You have been blocked by the server.".encode('utf-8'))
    client.close()

def send_messages():
    while True:
        if not message_queue.empty():
            priority, message = message_queue.get()
            broadcast(message)

def receive():
    while True:
        print('Server is running and listening ...')
        client, address = server.accept()
        print(f'Connection is established with {str(address)}')
        client.send('alias?'.encode('utf-8'))
        alias = client.recv(1024)
        aliases.append(alias)
        clients.append(client)
        print(f'The alias of this client is {alias}'.encode('utf-8'))
        broadcast(f'{alias} has connected to the chat room'.encode('utf-8'))
        client.send('You are now connected!'.encode('utf-8'))
        client_priority[client] = int(input("Enter priority level for the client: "))  # Set priority level
        thread = threading.Thread(target=handle_client, args=(client,))
        thread.start()

        # Check if the client should be blocked
        block_decision = input("Do you want to block this client? (yes/no): ")
        if block_decision.lower() == 'yes':
            block_client(client)

if __name__ == "__main__":
    send_thread = threading.Thread(target=send_messages)
    send_thread.start()
    receive()
