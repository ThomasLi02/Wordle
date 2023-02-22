Proposed Functional Requirements List:
1. Initial state: 6 rows of 5 boxes placed at the center of the screen with an
input box at the bottom of the screen (likely a 6 x 5 matrix array)

- Validation by playing (run 'Wordle'), observe boxes.

2. To take a guess, user types his answer to the input box. On key down,
the program prints the letter to the input box, if the key is delete,
the input box string pops the last letter.

- Validation by playing (run 'Wordle'), type letters and observe. Press delete and
 observe.

3. On key enter, the value of the input box is evaluated. The string of the box
is evaluated base based on its length, only allowing a word of length 5

- Validation by playing (run 'Wordle'), guess incorrect length word (non 5 letter
word), observe error

4. The error shows "Wrong # of Characters" if there are different than 5
characters

- Validation by playing (run 'Wordle'), type letters and observe. Enter more than
5 characters, and observe

5. There will also be a function that checks if the input is an actual English
word (if the word is in the English dictionary)

-Validation by check model_test Line 12-25 or checking code Model.cxx L 48-80

6. Once it satisfies both the length and an English word, the program evaluates
the string in comparison to the answer, it will return a string with characters
‘y’, ‘g’, ‘ ’, corresponding to yellow green and blank.

- Validation by checking model_test lines 55-67 or code Model.cxx L131-146

7. 	Given the string in with ‘y’ ‘g’ ‘b’ ,highlight the boxes with the
corresponding colors (we will using another 2d matrix containing character s’
‘y’ ‘g’ ‘ ’)

- Validation by playing (run 'Wordle'), type a 5 letter English word
press enter and observe

8. If there has been less than 6 guesses, and the user gets the word correct,
the program then asks for another input from the user.

- Validation by playing (run 'Wordle'), type "APPLE" and press enter

9. Once there are six guesses, if the last word is correct, do 8., otherwise do
8. but the user has lost

- Validation by playing (run 'Wordle'), type take 6 guesses other than"APPLE"

10. There will be another function that asks if the user want to up the level of
 the game by guessing a word with 6 characters (so our matrix will be 6x6)

- Validation by playing (run 'Wordle'), type "APPLE" and press enter then press
2

Sources for database:
5 Letter Words:
https://www-cs-faculty.stanford.edu/~knuth/sgb-words.txt

6 Letter Words:
http://www.poslarchive.com/math/scrabble/lists/common-6.html


