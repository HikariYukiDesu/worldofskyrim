using GameServer.Networking;
using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WOS.Domain;

namespace WOS.GameServer.MessageProcessing
{
    public class UpdateInfo
    {
        public Transform Transform { get; set; }
    }

    public class UpdateMessage : IMessage
    {
        public string Json { get; set; }
        public Connection Connection { get; set; }
        public void Process()
        {
            var loginInfo = JsonConvert.DeserializeObject<UpdateInfo>(Json);
            Connection.Player.Transform = loginInfo.Transform;
        }
    }
}
