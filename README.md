# 42_minitalk

42_minitalk est un projet de l'école 42 dans lequel nous devons créer un programme de communication sous la forme d'un client et d'un serveur utilisant des signaux UNIX.

## 📋 Règles

Le server doit être lancé en premier et doit afficher son PID (Process IDentifier).
Le client prendra comme paramètre :
* Le Pid du serveur
* La chaîne qui doit être envoyée

Le client doit communiquer au serveur la chaîne passée en paramètre et le serveur doit l'afficher. La communication ne doit se faire qu'en utilisant les signaux UNIX ```SIGUSR1``` et ```SIGUSR2```.

### ✨ Bonus Réalisés
* Le serveur confirme la réception de chaque message en envoyant un signal au client
* Prend en charge les caractères Unicode

## 🛠️ Usage

Utilisez la commande ```make``` pour compiler puis exécutez le serveur avec : 
```
./server
```
Ensuite exécutez le client sur un autre terminal avec :
```
./client <PID server> <string to send>
```
