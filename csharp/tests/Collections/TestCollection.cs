using tests.Fixtures;

using Xunit;

namespace tests.Collections
{
    [CollectionDefinition("TestCollection")]
    public class TestCollection : ICollectionFixture<TestStartupFixture>
    {

    }
}
