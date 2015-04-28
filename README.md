<h1>Project	Summary:</h1>

   <p> This project is an encryption library ment to take strings and make them more protected from unwanted viewers at the moment it primarily shuffles ASCII values </p>

<h1>How	to	Run:</h1>

When you initialize the Encryption class, you have two options:
<ol>
    <li>(int keylength, string yourMessage), this will make a random key of the length specified. I recommend a key 10-30% as long as the message</li>
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
</ul>

<h2><b>A link will go here (Task given to Cyron)(What do you mean by link)</b></h2>

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

    Cyron (Dwarfnado) Completo
    No one else
    
<h1>Open	issues/bugs:</h1>
   <ul>
   <li>Issue with multiple encryptions and attempting to decrypt back to original.</li>
   </ul>
