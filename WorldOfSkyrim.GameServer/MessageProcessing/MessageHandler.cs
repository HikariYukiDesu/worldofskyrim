using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WOS.GameServer.MessageProcessing;

namespace WOS.GameServer
{
    public class MessageHandler
    {
        public static void Handle(IMessage message)
        {
            message.Process();
        }
    }
}
