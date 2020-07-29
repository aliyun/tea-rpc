using System;
using System.Collections.Generic;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using AlibabaCloud.RPCClient;
using AlibabaCloud.RPCClient.Models;
using AlibabaCloud.TeaUtil.Models;
using Xunit;

namespace tests
{
    public class ClientTest
    {
        static HttpListener httpobj;

        public ClientTest()
        {
            if (httpobj == null)
            {
                //�ṩһ���򵥵ġ���ͨ����̷�ʽ���Ƶ� HTTP Э�������������಻�ܱ��̳С�
                httpobj = new HttpListener();
                //����url���˿ںţ�ͨ������Ϊ�����ļ�
                httpobj.Prefixes.Add("http://127.0.0.1:1500/");
                //����������
                httpobj.Start();
                //�첽�����ͻ������󣬵��ͻ��˵�����������ʱ���Զ�ִ��Resultί��
                //��ί��û�з���ֵ����һ��IAsyncResult�ӿڵĲ�������ͨ���ò�����ȡcontext����
                httpobj.BeginGetContext(Result, null);
                Console.WriteLine($"server init, waiting for request,time��{DateTime.Now.ToString()}\r\n");
            }
        }

        private static void Result(IAsyncResult ar)
        {
            //�����յ��������������ߵ�����

            //�����첽����
            httpobj.BeginGetContext(Result, null);
            var guid = Guid.NewGuid().ToString();
            Console.ForegroundColor = ConsoleColor.White;
            Console.WriteLine($"new request guid:{guid},time��{DateTime.Now.ToString()}");
            //���context����
            var context = httpobj.EndGetContext(ar);
            var request = context.Request;
            var response = context.Response;
            context.Response.ContentType = "application/json";//���߿ͻ��˷��ص�ContentType����Ϊ���ı���ʽ������ΪUTF-8
            context.Response.ContentEncoding = Encoding.UTF8;
            string returnObj = null;//���巵�ؿͻ��˵���Ϣ
            returnObj = HandleRequest(request, response);
            var returnByteArr = Encoding.UTF8.GetBytes(returnObj);//���ÿͻ��˷�����Ϣ�ı���
            try
            {
                using (var stream = response.OutputStream)
                {
                    //�Ѵ�����Ϣ���ص��ͻ���
                    stream.Write(returnByteArr, 0, returnByteArr.Length);
                }
            }
            catch (Exception ex)
            {
                Console.ForegroundColor = ConsoleColor.Red;
                Console.WriteLine($"connect error��{ex.ToString()}");
            }
            Console.ForegroundColor = ConsoleColor.Yellow;
            Console.WriteLine($"request finish guid��{guid},time��{ DateTime.Now.ToString()}\r\n");
        }

        private static string HandleRequest(HttpListenerRequest request, HttpListenerResponse response)
        {
            string data = null;
            string action = request.QueryString.Get("action");

            switch (action)
            {
                case "GetSuccess":
                    {
                        response.StatusDescription = "200";//��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬������ı�˵����
                        response.StatusCode = 200;// ��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬���롣
                        return "{\"result\": \"server test\"}";
                    }
                case "PostError":
                    {
                        response.StatusDescription = "400";//��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬������ı�˵����
                        response.StatusCode = 400;// ��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬���롣
                        return "{\"Message\": \"server server error\",\"Code\": \"400\"}";
                    }
            }
            response.StatusDescription = "200";//��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬������ı�˵����
            response.StatusCode = 200;// ��ȡ�����÷��ظ��ͻ��˵� HTTP ״̬���롣
            Console.ForegroundColor = ConsoleColor.Green;
            Console.WriteLine($"request finish:{data?.Trim()},time��{DateTime.Now.ToString()}");
            return $"�����������";
        }

        [Fact]
        public void Test_DoRequest()
        {
            var config = new Config
            {
                AccessKeyId = "access_key_id",
                AccessKeySecret = "access_key_secret",
                SecurityToken = "security_token",
                Protocol = "http",
                RegionId = "region_id",
                ReadTimeout = 1000,
                ConnectTimeout = 5000,
                Endpoint = "127.0.0.1:1500",
                MaxIdleConns = 1,
            };
            var runtime = new RuntimeOptions
            {
                Autoretry = false,
                MaxAttempts = 2
            };

            var client = new Client(config);
            var query = new Dictionary<string, object>();
            var res = client.DoRequest("GetSuccess", "http", "GET", "version", "auth_type", query, new Dictionary<string, object>(), runtime);
            Assert.Equal("server test", res["result"].ToString());

            var exception = Assert.Throws<Tea.TeaUnretryableException>(() =>
            {
                client.DoRequest("PostError", "http", "POST", "version", "auth_type", null, new Dictionary<string, object>(), runtime);
            });
            Assert.Contains("server server error", exception.Message);

        }

        [Fact]
        public async Task Test_DoRequestAsync()
        {
            var config = new Config
            {
                AccessKeyId = "access_key_id",
                AccessKeySecret = "access_key_secret",
                SecurityToken = "security_token",
                Protocol = "http",
                RegionId = "region_id",
                ReadTimeout = 1000,
                ConnectTimeout = 5000,
                Endpoint = "127.0.0.1:1500",
                MaxIdleConns = 1,
            };
            var runtime = new RuntimeOptions
            {
                Autoretry = false,
                MaxAttempts = 2
            };

            var client = new Client(config);
            var query = new Dictionary<string, object>();

            var res = await client.DoRequestAsync("GetSuccess", "http", "GET", "version", "auth_type", query, new Dictionary<string, object>(), runtime);
            Assert.Equal("server test", res["result"].ToString());

            var exception = await Assert.ThrowsAsync<Tea.TeaUnretryableException>(async () =>
            {
                await client.DoRequestAsync("PostError", "http", "POST", "version", "auth_type", null, new Dictionary<string, object>(), runtime);
            });
            Assert.Contains("server server error", exception.Message);
        }

    }
}
