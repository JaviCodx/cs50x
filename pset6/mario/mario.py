from cs50 import get_int


condition = True

while condition:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        condition = False
        
for row in range(1, height+1):
    print(' ' * (height - row) + '#' * row)
  
