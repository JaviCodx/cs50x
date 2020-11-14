from cs50 import get_float



while True:
    owed = get_float("Cash owed ")
    if owed >= 0:
        break
    
cents = round(owed*100)
coins = 0 

while(cents >= 25):
    coins += 1
    cents -= 25
    
while(cents >= 10):
    coins += 1
    cents -= 10

while(cents >= 5):
    coins += 1
    cents -= 5
    
while(cents >= 1):
    coins += 1
    cents -= 1
    
print(f"{coins}")