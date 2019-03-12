# crutch

# Компиляция

windows в папке src
``` bash
gcc *.c -o crutch.exe
```

linux в папке src
``` bash
gcc *.c
```

# Оформление функции

Файл лежит в src

```c
// Имя Фамилия
// Что делает функия
int funcName() {
  // если что то сложно то пишем комментарии
  return 0
}

```

# Тест функции

Например для функции сложения. Файл теста находится в папке test

```c

int add(int a, int b);

void pass() {
  puts(filename + pass);
}

void error(test Test) {
  puts(filename + error); // и где ошибка
}

typedef Test struct {
  In1 int
  In2 int
  Out int
}

int main() {
  Test tests[] = {
    {2,2,4},
    {3,3,6},
    ...
  }
  int i, flag = 1;
  for (i = 0;i < 10 && flag; i++) {
     if (add(test[i].In1, test[i].In2) != test[i].Out) {
      flag = 0;
  }
  if (flag) {
    pass();
  } else {
    error(test[i])
  }
}

```

# AutoTest

Если на линукс, то можно сохранить этот файл в папке crutch как test.sh. И запустить ./test.sh. Тесты все пройдут сами. 

```bash

#!/bin/sh

mkdir test_dir

cp src/*.c test_dir/
cp src/*.h test_dir/

B="$(ls src  | tr ' ' '\n')"
A="$(ls test | tr ' ' '\n')"
cd test_dir

for x in $B
do
	if [[ "$x" == "main.c" ]]
	then
		rm $x
	fi
done

for x in $A
do
	cp "../test/$x" "./"
	gcc *.c
	./a.out
	rm $x
done

cd ..
rm -rf test_dir


```
