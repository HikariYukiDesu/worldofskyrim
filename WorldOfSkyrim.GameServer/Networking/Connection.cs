using System;
using System.Net.WebSockets;
using System.Text;
using System.Threading.Tasks;
using Owin.WebSocket;
using WOS.Domain;
using WOS.GameServer;
using Newtonsoft.Json;
using WOS.GameServer.MessageProcessing;
using System.Collections.Generic;
using System.IO;
using WOS.GameServer.Networking;

namespace GameServer.Networking
{
    public class ClientRequest
    {
        public MessageType messageType;

        public string message;
    }

    public enum MessageType
    {
        login = 1,
        update
    }

    public class Connection : WebSocketConnection
    {
        public Player Player { get; set; } = new Player();

        public string Key { get; set; }
        
        public static List<Player> Npcs = new List<Player>();

        public override async Task OnMessageReceived(ArraySegment<byte> message, WebSocketMessageType type)
        {
            var json = Encoding.UTF8.GetString(message.Array, message.Offset, message.Count);
            var request = JsonConvert.DeserializeObject<ClientRequest>(json);

            switch (request.messageType)
            {
                case MessageType.login:
                    MessageHandler.Handle(new AuthorizeMessage { Connection = this, Json = request.message });
                    break;
                case MessageType.update:
                    MessageHandler.Handle(new UpdateMessage { Connection = this, Json = request.message });
                    break;
            }
        }

        public override void OnClose(WebSocketCloseStatus? closeStatus, string closeStatusDescription)
        {
            ConnectionRepository.Remove(Key);

            base.OnClose(closeStatus, closeStatusDescription);
        }
    }
}
