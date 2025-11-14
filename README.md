# projet-qualiteprog
Dépôt de projet dans le cadre du cours de qualité de programmation L3 MIAGE 

### Evaluation : 

L'évaluation se fait à partir d’un questionnaire. 
Présentation de la question, on lui demande la réponse 
On affiche la réponse en fonction du type d’évaluation

A la fin de l’évaluation : affichage des résultats (nb questions, nb d’essais, nb bonnes réponses)


3 types d'évaluations : 
Test : chaque question est posée dans l’ordre, on n’affiche pas les bonnes réponses
Seconde chance : une question est reposée une fois si la réponse est mauvaise, et on peut afficher la bonne réponse si la réponse était encore mauvaise 
Adaptative : les questions sont posées dans un ordre aléatoire et une question avec une mauvaise réponse sera reposée à la fin.


Principe : 
Pose une question du questionnaire
Évalue la réponse
Affiche les résultats à la fin du questionnaire


Classe abstraite Evaluation
Classe autre : EvaluationTest, EvaluationSecondeChance, EvaluationAdaptative 

