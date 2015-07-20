# Ashell

Projet de shell minimaliste pour expérimenter la programmation système.

## Notion abordé dans le projet

* gestion de processus (PID, fork)
* communication inter-processus par envoi de signaux

## Compilation et exécution

Chaque commande est à exécuter depuis la racine du projet : 

* Pour compiler, utilisez la commande `make`
* Pour lancer le projet, utilisez les commandes

		cd bin
		./ashell

## Utilisation

le shell peut exécuter toute commande dont l'exécutable est placé dans le répertoire `./bin` (situé à la racine du projet)

2 commandes sont pré-installées :

* aexit : quitte le shell et lui envoi un signal de fin pour qu'il s'arrête.

* toto : affiche du texte à l'écran en fonction de ses argument

    * `1` affiche toto
    * `2` affiche titi
    * `3` affiche tata
	
    Ex : toto 1 2 3 affichera : 

			toto
			titi
			tata





