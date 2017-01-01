using GameServer.Networking;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace WOS.GameServer.MessageProcessing
{
    public interface IMessage
    {
        string Json { get; set; }
        Connection Connection { get; set; }
        void Process();
    }
}
