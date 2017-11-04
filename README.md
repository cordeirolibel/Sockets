# Sockets
Comunicação de Dados: Ami Socket 

FLTK (C++)

![alt text](https://image.ibb.co/gaeadG/server.png)
![alt text](https://image.ibb.co/jSumkw/cliente.png)

#### AMI:

![alt text](https://upload.wikimedia.org/wikipedia/commons/thumb/b/b6/Ami_encoding.svg/320px-Ami_encoding.svg.png)

## Linux:
Instale os seguites pacotes:
```
sudo apt-get install make
sudo apt-get install gcc
sudo apt-get install g++
sudo apt-get install libfltk1.3-dev
sudo apt-get install libx11-dev
```

Na pasta dos arquivos executar:

```
make
```

Para executar o servidor:
```
./server_main
```

Para executar o cliente (Abrir outro terminal):
```
./client_main
```

## Windows (Somente executar):

Instale o Ubuntu Bash conforme o tutorial:
https://www.howtogeek.com/261383/how-to-access-your-ubuntu-bash-files-in-windows-and-your-windows-system-drive-in-bash/

Instale o Xming conforme o tutorial:
https://www.howtogeek.com/261575/how-to-run-graphical-linux-desktop-applications-from-windows-10s-bash-shell/

Com o Xming rodando usar Ubuntu Bash na pasta do projeto e executar
```
DISPLAY=:0 ./server_main
```

Para executar o cliente (Abrir outro Bash):
```
DISPLAY=:0 ./client_main
```

## Referências:

http://tldp.org/LDP/LG/issue74/tougher.html

http://www.fltk.org/doc-1.3/

https://www.youtube.com/watch?v=O9gWkLz8eZI
