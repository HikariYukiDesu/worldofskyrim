using GameServer.Networking;
using Owin;
using Owin.WebSocket.Extensions;

namespace GameServer.Hosting
{
    public class OwinHost
    {
        public void Configuration(IAppBuilder app)
        {
            app.MapWebSocketRoute<Connection>("/ws");
        }
    }
}
