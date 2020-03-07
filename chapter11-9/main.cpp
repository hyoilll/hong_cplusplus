/*
	다중 상속
*/

#include <iostream>

using namespace std;

class USBDevice
{
private:
	long m_id;

public:
	USBDevice(long id) :m_id(id) {}

	long getId()const { return m_id; }

	void plugAndPlay() {}
};

class NetworkDevice
{
private:
	long m_id;

public:
	NetworkDevice(long id) :m_id(id) {}

	long getId()const { return m_id; }

	void networking() {}
};

class USBNetworkDevice : public USBDevice, public NetworkDevice
{
public:
	USBNetworkDevice(long usb_id, long net_id) : USBDevice(usb_id), NetworkDevice(net_id) {}
};

int main()
{
	USBNetworkDevice d(3.14, 6.022);

	d.networking();
	d.plugAndPlay();

	//d.getId(); error발생 어느 쪽의 getid인지 알 수 없음.

	d.USBDevice::getId();
	d.NetworkDevice::getId();

	return 0;
}