#!/usr/bin/env python3

from socket import *

HOST = 'localhost'
PORT = 21567
BUFSIZE = 1024
ADDR = (HOST, PORT)

tcp_cli_sock = socket(AF_INET, SOCK_STREAM)
tcp_cli_sock.connect(ADDR)

while True:
    data = input('> ') #read input from standard input
    if not data:
        break
    tcp_cli_sock.send(data)
    data = tcp_cli_sock.recv(BUFSIZE)
    if not data:
        break
    print(data)

tcp_cli_sock.close()