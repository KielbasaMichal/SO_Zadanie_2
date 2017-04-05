import random

f = open('data.txt','w')
random.seed(f)
            
ile = 100

f.write(str(ile) + '\n')                         #ilosc danych

for i in range(ile):
    f.write(str(random.randint(0, 1000)) + '\t' + str(random.randint(50, 1000)) + '\n')  #Miejsce odwolania
    

f.close()
