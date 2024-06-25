#include &lt;iostream&gt;
#include &lt;string&gt;
#include &lt;vector&gt;
#include &lt;Windows.h&gt;
#include &lt;limits&gt;
#include &lt;cctype&gt;

using namespace std;
class BankAccount {
private:
	int AccountNumber;
	double balance;
	double interestRate;
public:
	BankAccount(int AccountNumber, double balance, double interestRate) {
		this - &gt; AccountNumber = AccountNumber;
		this - &gt; balance = balance;
		this - &gt; interestRate = interestRate;
	}
	void deposit(double amount) {
		balance += amount;
	}
	void withdraw(double amount) {
		if (amount& lt; 0) {
			cout& lt; &lt; &quot; Ошибка!&quot; &lt; &lt; endl;
			return;
		}
		if (balance - amount & lt; 0) {
			cout& lt; &lt; &quot; Ошибка!&quot; &lt; &lt; endl;
			return;
		}
		balance -= amount;
	}
	double getbalance() {
		return balance;
	}
	double getInterest() {
		return balance * interestRate * 1.0 / 12.0;
	}
	double setIneterestRate(double newInterestRate) {
		if (newInterestRate& lt; 0) {
			cout& lt; &lt; &quot; Ошибка!&quot; &lt; &lt; endl;
			return 0;
		}
		interestRate = newInterestRate;
		return newInterestRate;
	}

	int getAccountNumber() {
		return AccountNumber;
	}
	friend bool transfer(BankAccount& amp; n, BankAccount& amp; m, double amount) {
		if (amount& lt; 0) {
			cout& lt; &lt; &quot; Ошибка!&quot; &lt; &lt; endl;
			return false;
		}
		if (n.balance - amount & lt; 0) {
			cout& lt; &lt; &quot; Ошибка!&quot; &lt; &lt; endl;
			return false;
		}
		n.balance -= amount;
		m.balance += amount;
		return true;
	}
};
int main() {
	SetConsoleCP(1251);
	setlocale(LC_ALL, &quot; Russian & quot;);
	BankAccount account1(123456, 2000.0, 0.05);
	BankAccount account2(654321, 4000.0, 0.05);
	cout& lt; &lt; &quot; Баланс 1 аккаунта: &quot; &lt; &lt; account1.getbalance()& lt; &lt; endl;
	cout& lt; &lt; &quot; Проценты 1 аккаунта: &quot; &lt; &lt; account1.getInterest()& lt; &lt; endl;
	if (transfer(account1, account2, 500.0)) {
		cout& lt; &lt; &quot; Перевод выполнен& quot; &lt; &lt; endl;
	}
	else {
		cout& lt; &lt; &quot; Перевод не удался : (&quot; &lt; &lt; endl;
	}
	return 0;
}