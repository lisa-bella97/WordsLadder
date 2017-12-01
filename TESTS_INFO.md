#Описание тестов

1. `01_1.dat`, `01_2.dat` - содержат корректные входные данные (начальное и конечное слова и совокупность слов для построения словесной лестницы, при этом начальное и конечное слова принадлежат этой совокупности)  
   `01.ans` - содержит корректную лестницу слов

2. `02_1.dat`, `02_2.dat` - содержат некорректные входные данные (первый файл пустой)  
   `02.ans` - содержит сообщение *"Cannot build a ladder of words"*

3. `03_1.dat`, `03_2.dat` - содержат корректные входные данные (начальное и конечное слова из цифр и совокупность слов для построения словесной лестницы, при этом начальное и конечное слова не принадлежат этой совокупности)  
   `03.ans` - содержит корректную лестницу слов

4. `04_1.dat`, `04_2.dat` - содержат некорректные входные данные (второй файл пустой)  
   `04.ans` - содержит сообщение *"Cannot build a ladder of words"*

5. `05_1.dat`, `05_2.dat` - содержат корректные входные данные (начальное и конечное слова и совокупность слов для построения словесной лестницы, но между начальным и конечным словами нельзя построить лестницу слов)  
   `05.ans` - содержит сообщение *"Cannot build a ladder of words"*

6. `06_1.dat`, `06_2.dat` - содержат корректные входные данные (начальное и конечное слова и совокупность слов для построения словесной лестницы, имеется несколько путей от начального слова да конечного)  
   `06.ans` - содержит корректную лестницу слов (минимальный путь)

7. `07.dat` - содержит корректные входные данные (начальное и конечное слова, разделенные несколькими пробельными символами и не содержащиеся в файле `words.txt`)  
   `07.ans` - содержит корректную лестницу слов

8. `08.dat` - содержит корректные входные данные (начальное и конечное слова, отличающиеся друг от друга одной буквой)  
   `08.ans` - содержит корректную лестницу слов (сами эти слова)
   
9. `09.dat` - содержит корректные входные данные (равные друг другу начальное и конечное слова)  
   `09.ans` - содержит корректную лестницу слов (сами эти слова)

10. `10.dat` - содержит корректные входные данные (начальное и конечное слова, содержащиеся в файле `words.txt`)  
    `10.ans` - содержит корректную лестницу слов