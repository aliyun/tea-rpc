using System.Net;

using tests.Fixtures;

using Xunit;

namespace tests
{
    [Collection("TestCollection")]
    public class TestBase
    {
        protected readonly HttpListener _httpobj;

        public TestBase(TestStartupFixture fixture)
        {
            _httpobj = fixture.httpobj;
        }
    }
}
