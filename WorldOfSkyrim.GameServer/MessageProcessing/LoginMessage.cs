using GameServer.Networking;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WOS.Domain;
using WOS.GameServer.Networking;

namespace WOS.GameServer.MessageProcessing
{
    public class LoginInfo
    {
        public string Nick { get; set; }

        public Transform Transform { get; set; }
    }

    public class AuthorizeMessage : IMessage
    {
        public string Json { get; set; }
        public Connection Connection { get; set; }
        public void Process()
        {
            var loginInfo = JsonConvert.DeserializeObject<LoginInfo>(Json);
            
            if (string.IsNullOrEmpty(Connection.Key))
            {
                Connection.Player.Name = loginInfo.Nick;
                Connection.Player.Transform = loginInfo.Transform;
                ConnectionRepository.Register(Connection);
            }
            else
            {
                uint result;
                if (uint.TryParse(loginInfo.Nick, out result) && CharacterNpcInterpreter.Ids.ContainsKey(result)) {
                    Connection.Npcs.Add(new Player { Name = CharacterNpcInterpreter.Ids[result].ToString(), Transform = loginInfo.Transform });
                }
            }
        }
    }
}
