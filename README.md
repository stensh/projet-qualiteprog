# projet-qualiteprog
Dépôt de projet dans le cadre du cours de qualité de programmation L3 MIAGE 

## Objectif du projet 

On souhaite pouvoir gérer des questionnaires dans le but de les utiliser pour l'apprentissage ou l'évaluation. 

### Questionnaire 

Un questionnaire est composé d'un titre et de questions.
On veut pouvoir manipuler trois types de questions : 

- Question texte : intitulé, texte, réponse (texte). Il faut donner un texte égal à la réponse pour valider la question.
- Question numérique : intitulé, texte, réponse (nombre entier), limite minimale, limite maximale. Il faut donner un entier compris entre les limites pour valider la question.
- Question à choix multiples : intitulé, texte, quatres réponses (texte), numéro de la bonne réponse. Il faut donner un texte égal à la réponse ayant pour numéro celui de la bonne réponse pour valider la question.

### Apprentissage

L'apprentissage se fait par l'affichage consécutif des différents intitulés de questions et leurs réponses.

### Évaluation : 

L'évaluation se fait à partir d’un questionnaire. 
Affichage de la question et demande de réponse.
On affiche la réponse en fonction du type d’évaluation.

À la fin de l’évaluation : affichage des résultats (nombre de questions, nombre d’essais, nombre de bonnes réponses)


On veut pouvoir réaliser trois types d'évaluation :

- Évaluation test : chaque question est posée dans l’ordre, on n’affiche pas les bonnes réponses.
- Évaluation seconde chance : une question est reposée une fois si la réponse est mauvaise, et on peut afficher la bonne réponse si la réponse est une deuxième fois mauvaise.
- Évaluation adaptative : les questions sont posées dans un ordre aléatoire et une question avec une mauvaise réponse sera reposée à la fin.

