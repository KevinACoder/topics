#!/usr/bin/env python3

from socket import *
from time import ctime

HOST = ''
PORT = 21567
BUFSIZE = 1024
ADDR = (HOST, PORT)

tcp_srv_sock = socket(AF_INET, SOCK_STREAM)
tcp_srv_sock.bind(ADDR)
tcp_srv_sock.listen(5)

while True:
    print('waiting connection...')
    tcp_cen_sock, addr = tcp_srv_sock.accept()
    print('connect from', addr)

    while True:
        data = tcp_cen_sock.recv(BUFSIZE)
        if not data:
            break
        tcp_cen_sock.send('[%s]%s'%(ctime(),data))

    tcp_cen_sock.close()
tcp_srv_sock.close()