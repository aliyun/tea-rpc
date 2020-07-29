using System;
using System.Collections.Generic;
using System.Net;
using System.Text;
using System.Threading.Tasks;

using AlibabaCloud.RPCClient;
using AlibabaCloud.RPCClient.Models;
using AlibabaCloud.TeaUtil.Models;

using tests.Fixtures;

using Xunit;

namespace tests
{
    public class ClientTest : TestBase
    {

        public ClientTest(TestStartupFixture fixture) : base(fixture)
        { }

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

            var exception = await Assert.ThrowsAsync<Tea.TeaUnretryableException>(async() =>
            {
                await client.DoRequestAsync("PostError", "http", "POST", "version", "auth_type", null, new Dictionary<string, object>(), runtime);
            });
            Assert.Contains("server server error", exception.Message);
        }

    }
}
