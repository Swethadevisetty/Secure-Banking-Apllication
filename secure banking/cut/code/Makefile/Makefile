a.out:  main.o account.o checkbalance.o editdetails.o homepage.o login.o withdraw.o deposit.o
	 gcc main.o account.o checkbalance.o editdetails.o homepage.o login.o withdraw.o deposit.o -o a.out

main.o: src/main.c 
	gcc -c src/main.c

account.o: src/account.c include/bank.h
	gcc -c src/account.c

checkbalance.o: src/checkbalance.c include/bank.h
	gcc -c src/checkbalance.c

editdetails.o: src/editdetails.c include/bank.h
	gcc -c src/editdetails.c

homepage.o: src/homepage.c include/bank.h
	gcc -c src/homepage.c

login.o: src/login.c include/bank.h
	gcc -c src/login.c

withdraw.o: src/withdraw.c include/bank.h
	gcc -c src/withdraw.c

deposit.o: src/deposit.c include/bank.h
	gcc -c src/deposit.c

