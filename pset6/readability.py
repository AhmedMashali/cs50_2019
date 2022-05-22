from cs50 import get_string

s = get_string("Text: ")

letters = 0;
words = 1;
sentences = 0;


for i in s:
    if i == ' ':
        words += 1
    elif i in ['!', '?', '.']:
        sentences += 1
    elif (i.isnumeric() or i.isalpha()):
        letters += 1


L = (letters * 100) / words
S = (sentences * 100) / words

index = 0.0588 * L - 0.296 * S - 15.8;


if index < 1:
    print("Before Grade 1")

elif index >= 16:
    print("Grade 16+")

else:
    print("Grade",int(round(index)))