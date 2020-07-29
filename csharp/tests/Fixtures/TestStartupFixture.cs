using System;
using System.Net;
using System.Text;

namespace tests.Fixtures
{
    public class TestStartupFixture : IDisposable
    {
        public HttpListener httpobj { get; set; }

        public TestStartupFixture()
        {
            httpobj = new HttpListener();
            httpobj.Prefixes.Add("http://127.0.0.1:1500/");
            httpobj.Start();
            httpobj.BeginGetContext(Result, null);
        }

        private void Result(IAsyncResult ar)
        {
            httpobj.BeginGetContext(Result, null);
            var context = httpobj.EndGetContext(ar);
            var request = context.Request;
            var response = context.Response;
            context.Response.ContentType = "application/json";
            context.Response.ContentEncoding = Encoding.UTF8;
            string returnObj = null;
            returnObj = HandleRequest(request, response);
            var returnByteArr = Encoding.UTF8.GetBytes(returnObj);

            using(var stream = response.OutputStream)
            {
                stream.Write(returnByteArr, 0, returnByteArr.Length);
            }

        }

        private static string HandleRequest(HttpListenerRequest request, HttpListenerResponse response)
        {
            string action = request.QueryString.Get("action");

            switch (action)
            {
                case "GetSuccess":
                    {
                        response.StatusDescription = "200";
                        response.StatusCode = 200;
                        return "{\"result\": \"server test\"}";
                    }
                case "PostError":
                    {
                        response.StatusDescription = "400";
                        response.StatusCode = 400;
                        return "{\"Message\": \"server server error\",\"Code\": \"400\"}";
                    }
                default:
                    {
                        response.StatusDescription = "200";
                        response.StatusCode = 200;
                        break;
                    }
            }
            return $"Success";
        }

        public void Dispose()
        {
            //dispose
        }
    }
}
