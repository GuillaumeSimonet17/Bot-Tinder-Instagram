Ce que fait le bot:

Swipe tous les profils vers la droite de façon humaine, avec un swipe vers la gauche tous les 100 swipes environ.
Programmer sur 200 swipes. Pour modifier ce nombre, allez sur "bot.py" et modifier la valeur de "nbr_of_swipes".
Récupère tous les profils instagram rencontrés sur son chemin, et les envoi dans le fichier "new_tinder_data.txt".
Envoi un DM instagram aux profils trouvés. Pour modifier ce message, allez dans "insta.py" et modifier l'argument dans "input_1.send_keys".
Si le compte est privé, le bot ne peux pas envoyer de DM, donc il suit le profil et le met dans le fichier "await_to_accept.txt".

Comment le faire fonctionner :

Dans le dossier Tinder Bot :
1 - Lancer script-run.sh
2 - decocher comme sur la photo
3 - Connectez sur tinder et gardez la page ouverte
4 - Lancer bot.py (200 swipe default)
5 - recuperez le fichier new_tinder_data.txt et copier coller le dans le dossier 'bot insta' (si vous voyez des mots que vous savez ne pas etre des profils insta, enlevez-les)

Dans le dossier Insta Bot :
1 - Lancer script-run.sh
2 - decocher comme sur la photo
3 - Connectez sur insta et gardez la page ouverte
4 - Lancer insta.py
5 - Attendez quelques jours qu'elles acceptent et copier coller les noms du fichier "await_to_accept" dans "new_tinder_data"