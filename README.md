# Bot-Tinder-Instagram


<h2>What the bot does:</h2>

- Swipes all profiles to the right in a human way.

- Programmed to 200 swipes. To change this number, go to "bot.py" and change the value of "nbr_of_swipes".

- Get all the instagram profiles found, and places them in the file "new_tinder_data.txt".

- Sends an instagram DM to the found profiles. To modify the message, go to "insta.py" and modify the argument in "input_1.send_keys".

- If the account is private, the bot can't send DM, so it follows the profile and put it in the file "await_to_accept.txt".

<br>
<h2>How it work:</h2>

<h4><strong>In the Tinder Bot folder :</strong></h4>


1 - Run script-run.sh.

2 - Uncheck as on the picture.

<img width="486" alt="Capture d’écran 2023-02-07 à 15 55 01" src="https://user-images.githubusercontent.com/84441663/217630495-1a65d640-4774-4528-9577-c93ab2f69c2b.png">

3 - Connect to tinder and keep the page open.

4 - Run bot.py (200 swipe default).

5 - Get the file new_tinder_data.txt and copy-paste it in the 'insta bot' folder (if you see words that you know are not insta profiles, remove them - this is not perfect).

<br>
<h4><strong>In the Insta Bot folder :</strong></h4>
<br>

1 - Run script-run.sh.

2 - Uncheck as on the picture above.

3 - Connect to insta and keep the page open.

4 - Launch insta.py.

5 - The DM are being sent. Wait a few days for the private accounts to accept and copy-paste the names of the file "await_to_accept" in "new_tinder_data".

6 - Enjoy

