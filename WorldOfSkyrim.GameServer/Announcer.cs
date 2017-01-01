using GameServer.Networking;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WOS.GameServer.Networking;

namespace WOS.GameServer
{
    public class Announcer
    {
        public static void EchoPlayerPositions()
        {
            var characters = ConnectionRepository.GetAllPlayers();
            if (characters != null)
            {
                characters.AddRange(Connection.Npcs);
                ConnectionRepository.Echo(JsonConvert.SerializeObject(characters));
            }
        }
    }
}
