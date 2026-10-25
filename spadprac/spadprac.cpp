#include <iostream> 
#include <string>
using namespace std;
class Notification {
protected: 
	string message;
	string timestamp;
public:
	Notification(string message, string timestamp)
	{ 
		this->message = message;
		this->timestamp = timestamp; 
	}
};
class EmailNotification : public Notification
{
private:
	string emailAddress;
public:
	EmailNotification(string message, string timestamp, string emailAddress) : Notification(message, timestamp)
	{
		this->emailAddress = emailAddress;
	}
	void send()
	{
		cout << "Відправка email на " << emailAddress << ": "
			<< message << '\n';
	}
};
class PushNotification : public Notification {
private:
	string deviceId;
public:
	PushNotification(string message, string timestamp, string deviceId) : Notification(message, timestamp)
	{
		this->deviceId = deviceId;
	}
	void send()
	{
		cout << "Відправка пуша на пристрій " << deviceId << ": "
			<< message << '\n';
	}
};
int main() {
	EmailNotification email("Ваше замовлення прийнято",
		"25.10.2026 12:56",
		"hahdeufwp@gmail.com");
	PushNotification push(
		"У вас нове повідомлення",
		"25.10.2026 13:43",
		"iPhone_12"
	);

	email.send();
	push.send();


};
