from cs50 import get_string

text = get_string("Text: ")
letters = sentences = 0
words = 1

for char in text:
    if char.isalpha():
        letters += 1
    elif char.isspace():
        words += 1
    elif char in['?', '!', '.']:
        sentences +=1

L = (letters * 100) / words
S = (sentences * 100) / words
total = round(0.0588 * L - 0.296 * S- 15.8)

if total < 1:
    print("Before grade 1")
elif total >= 16:
    print("Grade 16+")
else:
    print(f"Grade {total}")

