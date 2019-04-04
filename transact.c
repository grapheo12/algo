#include <stdio.h>
#include <string.h>

struct customer{
  int ac;
  char name[51];
  int balance;
};

int transaction(int account_number, int request_type, int amount, struct customer bank[10]){
  int i;
  for (i = 0; i < 10; i++){
    if (bank[i].ac == account_number)
      break;
  }

  if (request_type == 0){
    bank[i].balance += amount;
  }else if (request_type == 1){
    if (amount > bank[i].balance)
      return 0;

    bank[i].balance -= amount;
  }
  printf("Balance: %d\n", bank[i].balance);
  return 1;
}

int main(){
  struct customer bank[10];
  int i;
  for (i = 0; i < 5; i++){
    bank[i].ac = i;
    strcpy(bank[i].name, "Vijay Malya");
    bank[i].balance = i * 1000;
  }
  //Do whatever you like from here.
  transaction(1, 1, 100, bank);

  return 0;
}
