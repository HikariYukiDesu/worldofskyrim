using GameServer.Networking;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using WOS.Domain;

namespace WOS.GameServer.Networking
{
    public class ConnectionRepository
    {
        private static Dictionary<string, Connection> _connections = new Dictionary<string, Connection>();
        private static List<Player> CachedPlayers;
        private static Connection[] CachedConnections;
        public static void Register(Connection connection)
        {
            var key = Guid.NewGuid().ToString();
            _connections.Add(key, connection);
            connection.Key = key;
            CachedConnections = _connections.Values.ToArray();
            CachedPlayers = CachedConnections.Select(c => c.Player).ToList();
        }

        public static List<Player> GetAllPlayers()
        {
            return CachedPlayers;  
        }

        public static void Echo(string json)
        {
            foreach (var conn in CachedConnections)
            {
                if (_connections.ContainsKey(conn.Key))
                {
                    conn.SendText(Encoding.ASCII.GetBytes(json), true);
                }
            }
        }

        public static void Remove(string key)
        {
            _connections.Remove(key);
        }
    }
}
