#include <thread>

#include "../../dep/oscpack/ip/IpEndpointName.h"
#include "../../dep/oscpack/ip/UdpSocket.h"
#include "../../dep/oscpack/osc/OscPacketListener.h"
#include "../../dep/oscpack/osc/OscReceivedElements.h"

#define RX_ENDPOINT "127.0.0.1"
#define RX_PORT 7001

struct OscReceiver : public osc::OscPacketListener {
  OscReceiver();
  ~OscReceiver();

  IpEndpointName endpoint;
  UdpListeningReceiveSocket* rxSocket = NULL;
	std::thread listenerThread;

  void startListener();
  void endListener();
  void ProcessMessage(
    const osc::ReceivedMessage& message,
    const IpEndpointName& remoteEndpoint
  ) override;
};
