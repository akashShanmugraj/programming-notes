# python client code

import socket

IP = "127.0.0.1"
PORT = 4455
ADDR = (IP, PORT)
SIZE = 1024
FORMAT = "utf-8"


def main():
    """TCP Socket"""
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(ADDR)

    """ Recv data """
    data = client.recv(SIZE).decode(FORMAT)
    print(f"[SERVER] {data}")

    """ Send data """
    data += " From CLIENT"
    client.send(data.encode(FORMAT))

    """ Close connection """
    client.close()


if __name__ == "__main__":
    main()
