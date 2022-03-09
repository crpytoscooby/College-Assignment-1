import socket

HEADER = 64
# IP = socket.gethostbyname(socket.gethostname())
IP = "127.0.0.1"
PORT = 5050
ADDR = (IP, PORT)
FORMAT = 'utf-8'
DISCONNECT_MESSAGE = "!DISCONNECT"

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client.connect(ADDR)


def main():
    pass


if __name__ == "__main__":
    main()
