using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Net;
using System.Threading;
using System.Threading.Tasks;
using Microsoft.WindowsAzure;
using Microsoft.WindowsAzure.Diagnostics;
using Microsoft.WindowsAzure.ServiceRuntime;
using Microsoft.WindowsAzure.Storage;
using Microsoft.Owin.Hosting;
using GameServer.Hosting;
using WOS.GameServer;
using System.IO;

namespace WorldOfSkyrim.GameServer
{
    public class WorkerRole : RoleEntryPoint
    {
        private readonly CancellationTokenSource cancellationTokenSource = new CancellationTokenSource();
        private readonly ManualResetEvent runCompleteEvent = new ManualResetEvent(false);

        public override void Run()
        {
            Trace.TraceInformation("WorldOfSkyrim.GameServer is running");

            try
            {
                this.RunAsync(this.cancellationTokenSource.Token).Wait();
            }
            finally
            {
                this.runCompleteEvent.Set();
            }
        }

        public override bool OnStart()
        {
            // Set the maximum number of concurrent connections
            ServicePointManager.DefaultConnectionLimit = 12;

            // For information on handling configuration changes
            // see the MSDN topic at https://go.microsoft.com/fwlink/?LinkId=166357.

            bool result = base.OnStart();

            Trace.TraceInformation("WorldOfSkyrim.GameServer has been started");

            return result;
        }

        public override void OnStop()
        {
            Trace.TraceInformation("WorldOfSkyrim.GameServer is stopping");

            this.cancellationTokenSource.Cancel();
            this.runCompleteEvent.WaitOne();

            base.OnStop();

            Trace.TraceInformation("WorldOfSkyrim.GameServer has stopped");
        }

        private async Task RunAsync(CancellationToken cancellationToken)
        {
            var lines = File.ReadAllLines("characterNpcInterpret.txt");
            foreach (var line in lines)
            {
                var splittedLine = line.Split('=');
                if (!string.IsNullOrEmpty(splittedLine[1])) {
                    CharacterNpcInterpreter.Ids.Add(uint.Parse(splittedLine[0]), splittedLine[1]);
                }
            }

            using (WebApp.Start<OwinHost>(url: "http://*:9000"))
            {
                while (!cancellationToken.IsCancellationRequested)
                {
                    Announcer.EchoPlayerPositions();
                    await Task.Delay(200);
                    Announcer.EchoPlayerPositions();
                    await Task.Delay(200);
                    Announcer.EchoPlayerPositions();
                    await Task.Delay(200);
                    Announcer.EchoPlayerPositions();
                    await Task.Delay(200);
                    Trace.TraceInformation("Working");
                }
            }
        }
    }
}