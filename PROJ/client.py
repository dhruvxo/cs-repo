import threading
import socket
import os
import time

alias = input('Choose a username: ')
client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(('10.30.201.64', 59001))

# Function to receive messages on the client end
def client_receive():
    while True:
        try:
            message = client.recv(1024).decode('utf-8')
            if not message:
                print('Connection to the server is closed.')
                break
            if message == "alias?":
                client.send(alias.encode('utf-8'))
            elif message.startswith(f'{alias} has shared a file:'):
                _, filename = message.split(': ')
                filename = filename.strip()
                print(f'Receiving file: {filename}')
                receive_file(filename)
            else:
                print(message)
        except ConnectionResetError:
            print('Connection to the server was reset.')
            break
        except Exception as e:
            print(f'Error: {e}')
            client.close()
            break

# Function to send messages from the client to another client
def client_send():
    while True:
        message = input("")
        if not client:
            break  # The loop will exit if the client socket is closed

        if message.startswith("/file"):
            _, file_path = message.split(" ")
            file_path = file_path.strip()
            # Check if the file size is above 10 MB
            file_size = os.path.getsize(file_path)
            if file_size > 10 * 1024 * 1024:  # 10 MB in bytes
                print("Error: File size exceeds the limit of 10MB. The file will not be sent.")
            else:
                send_file(file_path)
        else:
            if client:
                message = f'{alias}: {message}'
                client.send(message.encode('utf-8'))

# Function to send Files
def send_file(file_path):
    try:
        file_name = os.path.basename(file_path)
        file_size = os.path.getsize(file_path)
        client.send(f'/file|{file_name}|{file_size}'.encode('utf-8'))
        with open(file_path, 'rb') as file:
            while True:
                data = file.read(4096)
                if not data:
                    break
                client.send(data)
        # Delay to wait for the file to be sent
        time.sleep(1)
        client.send(b'<END_OF_FILE>')
        print(f'{file_name} sent successfully!')
        # Do not close the client socket here
    except Exception as e:
        print(f'Error while sending file: {e}')
        client.close()  # Close the connection in case of an error

# Function to receive files
def receive_file(file_name):
    try:
        with open(file_name, 'wb') as file:
            while True:
                data = client.recv(4096)
                if data == b'<END_OF_FILE>':
                    break
                file.write(data)
        print(f'{file_name} received successfully!')
    except Exception as e:
        print(f'Error while receiving file: {e}')

receive_thread = threading.Thread(target=client_receive)
receive_thread.start()

send_thread = threading.Thread(target=client_send)
send_thread.start()