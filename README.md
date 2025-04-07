# 寫題目前先閱讀下文

> 部分的題目敘述都缺東缺西，若題目在下面的列表中出現，可以在閱讀完原題後查看補充說明。
> 若想透過自己 Debug 解決，可忽略下文

### TS0604

<details>
  <summary>補充測資</summary>

  ```cpp
  #include "VecNf.h"
  #include <iostream>
  using namespace std;
  
  int main() {
  VecNf empty;
  float a_value[] = {3.0, 2.0};
  float b_value[] = {1, 2, 3};
  float c_value[] = {6, 5, 4};
  VecNf A(a_value, 2);
  VecNf B(b_value, 3);
  VecNf C(c_value, 3);
  VecNf T;
  T = A; // Assignment
  for (int i = 0; i < T.Size(); i++) {
  cout << T[i] << " ";
  }
  cout << endl;
  
  T = B; // Assignment
  for (int i = 0; i < T.Size(); i++) {
  cout << T[i] << " ";
  }
  cout << endl;
  
  T = B + C; // Vector addition
  for (int i = 0; i < T.Size(); i++) {
  cout << T[i] << " ";
  }
  cout << endl;
  
  cout << C * B << endl; // Scale
  
  cout << A * C << endl; // Inconsistent
  
  VecNf improveCase1;
  improveCase1[1000] = 99;
  std::cout << improveCase1[1000] << '\n';
  std::cout << improveCase1[10000] << '\n';
  
  return 0;
  }
  ```

</details>
<details>
  <summary>Output</summary>

  ```
  ASSIGNMENT!!!
  3 2 
  ASSIGNMENT!!!
  1 2 3 
  ASSIGNMENT!!!
  7 7 7 
  28
  dimensions inconsistent
  0
  99
  0
  
  ```

</details>

### TS0605

<details>
  <summary>補充測資</summary>

  ```cpp
  #include "Creature.h"
  #include "Diary.h"
  
  int main() {
      Diary::NewDay("0000");
      Creature unknownA("UA");
      unknownA["leg"] = 16;
  
      Diary::NewDay("0102");
      Creature unknownB("UB", unknownA);
      unknownB["leg"] += 26;
      unknownA.PrintLog();
  
      Diary::NewDay("0227");
      unknownA["leg"] = 0;
      unknownA.PrintStatus();
      unknownB.PrintLog();
  
      Diary::NewDay("0353");
      unknownA["leg"] += 6;
      unknownA["wing"] += 4;
      unknownA.PrintLog();
  
      Diary::NewDay("1A");
      Creature unknownC("UC");
      unknownC["leg"] += 6;
      unknownC["leg"] += -2;
      unknownC["leg"] -= 4;
      unknownC.PrintStatus();
      unknownC.PrintLog();
  
      Diary::NewDay("2A");
      unknownC["leg"] -= -2;
      unknownC.PrintStatus();
      unknownC.PrintLog();
  
      Diary::NewDay("1A");
      unknownC["leg"] = 3;
      unknownC.PrintStatus();
      unknownC.PrintLog();
  }
  ```

</details>
<details>
  <summary>Output</summary>

  ```
  UA's log:
  Day 0000
  UA's leg appeared (0 -> 16).
  Day 0102
  
  UA's status:
  
  UB's log:
  Day 0102
  UB's leg increased (16 -> 42).
  Day 0227
  
  UA's log:
  Day 0000
  UA's leg appeared (0 -> 16).
  Day 0102
  Day 0227
  UA's leg decreased (16 -> 0).
  Day 0353
  UA's leg appeared (0 -> 6).
  UA's wing appeared (0 -> 4).
  
  UC's status:
  
  UC's log:
  Day 1A
  UC's leg appeared (0 -> 6).
  UC's leg decreased (6 -> 4).
  UC's leg decreased (4 -> 0).
  
  UC's status:
  leg * 2
  
  UC's log:
  Day 1A
  UC's leg appeared (0 -> 6).
  UC's leg decreased (6 -> 4).
  UC's leg decreased (4 -> 0).
  Day 2A
  UC's leg appeared (0 -> 2).
  
  UC's status:
  leg * 3
  
  UC's log:
  Day 1A
  UC's leg appeared (0 -> 6).
  UC's leg decreased (6 -> 4).
  UC's leg decreased (4 -> 0).
  Day 2A
  UC's leg appeared (0 -> 2).
  Day 1A
  UC's leg increased (2 -> 3).
  

  ```

</details>

### TS0803

<details>
  <summary>補充說明</summary>
  輸入測資 String 包含空白字元

  > `Set 2 char 33`  
  char 僅代表資料大小，不代表輸入輸出格式。

  > `if the size of value exceeds the size of type, the excess part will be ignored`  
  輸入資料大小若溢出之前指定的類型，需要忽略掉多餘的部分。換句話說，輸入資料可以很大。

  > `and if overflow occurs (position + type size > N), please output "Violation Access".`  
  測資與題意不合。應該為「若當下要寫的一個位址超出記憶體大小，則輸出 "Violation Access" 且停止當次寫入動作」。換句話說，嘗試寫到寫不下為止。

</details>
