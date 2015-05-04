<h1>Project	Summary:</h1>

   <p> This project is an encryption library meant to take strings and protect them from unwanted viewers. At the moment it primarily shuffles ASCII values. </p>

<h1>How	to	Run:</h1>

When you initialize the Encryption class, you have two options:
<ol>
    <li>(int keylength, string yourMessage), this will make a random key of the length specified. I recommend a key 10-30% as long as the message. Note: the key value must be greater than 1</li>
    <li>(string yourKey, string yourMessage), this alows for you to put in your own custom string, either to speed up decryption or to put weird characters in your key, any ASCII character will work</li> 
</ol>

After you have the Encryption initialized you can:
<ul>
<li>call the decrypt() function with a key to try and extract a string that makes sense</li>
<li>call the encrypt() function to encrypt your message with the curent key</li>
<li>call getstring() to get the current state of the message</li>
<li>call getkey() to get the current key</li>
<li>call generatekey(int keyLength) to generate a new random key of that length (WARNING: this will replace the old key)</li>
<li>call manualkey(string key) to change the key to what you entered, works for all ASCII characters (WARNING: this will replace the old key)</li>
<li>getbase() get the current base</li>
<li>setbase(int > 0) sets the current base</li>
<li>encriptshift(string keyfragment) shift the ASCII values based on the keyfragment</li>
<li>decriptshift(string keyfragment) shift the ASCII values based on the keyfragment</li>
<li>encryptrandom(char keyfragment) add random characters at intervals determined by key</li>
<li><p>decriptrandom(char keyfragment) remove letters at set intervals (WARNING will remove actual characters from the message if not used after a call of encriptrandom with the same key)</p></li>
</ul>

<h2>Note: See the main.cpp for how to use the program.</h2>

<h1>Dependencies:</h1>

<p>The program includes the random library, the iostream library, the queue library, the stdio.h library, the string library, the vector library and the iostream library.  All of these libraries come packaged with C++.</p>


<h1>System	Requirements:</h1>

  C++
  
<h1>Group	Members:</h1>

<ul>
    <li>Nicholas Pfeufer</li> 
    <li>Tanner Tracy</li> 
    <li>Cyron Completo</li>
    <li>Harrison Snook</li>
</ul>

<h1>Contributors:</h1>
   <p>No one yet. If you would like to be listed as a contributor, leave a comment listing the changes you've made.</p>
<h1>Open	issues/bugs:</h1>
   <p>No issues currently. Please let us know in the issues section if you find anything.</p>
