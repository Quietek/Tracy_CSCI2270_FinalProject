<h1>Project	Summary:</h1>

   <p> This project is an encription librabary ment to take strings and make them more protected from unwanted viewers at the moment it primarilly shuffels ASCII values </p>

<h1>How	to	Run:</h1>

When you initilize the Encription class, you have two options:
<ol>
    <li>(int keylength, string yourMessage), this will make a random key of the length specified I recomend a key 10-30% as long as the message</li>
    <li>(string yourKey, string yourMessage), this alows for you to put in your own custom string, either to speed up decription or to put weird characters in your key, any ASCII character will work</li> 
</ol>

After you have the Encription initilized you can:
<ul>
<li>call the decrypt() function with a key to try and extract a string that makes sense</li>
<li>call the encrypt() function to encript your message with the curent key</li>
<li>call getstring() to get the current state of the message</li>
<li>call getkey() to get the curent key</li>
<li>call generatekey(int keyLength) to generate a new random key of that length (WARNING: this will replace the old key)</li>
<li>call manualkey(string key) to change the key to what you entered, works for all ASCII characters (WARNING: this will replace the old key)</li>
</ul>

<h2><b>A link will go here (Task given to Cyron)</b></h2>

<h1>Dependencies:</h1>

<p>The program includes the random library, the iostream library, the queue library, the stdio.h library, the string library, and the iostream library.  All of these libraries come packaged with C++  .</p>


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

    No one, make a comment and see your name here! (maybe, I make no promises)
    
<h1>Open	issues/bugs:</h1>
   <p> Hopefully none. Find a bug? Help us squash it and become a contributor/hero/best-person-ever in less time then the eventual heat death of the universe.</p>
