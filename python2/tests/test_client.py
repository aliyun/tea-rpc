# -*- coding: utf-8 -*-
from unittest import TestCase

from alibabacloud_tea_rpc.client import Client
from alibabacloud_tea_rpc.models import Config
from alibabacloud_tea_util.models import RuntimeOptions
from Tea.exceptions import TeaException, UnretryableException

import threading
from BaseHTTPServer import HTTPServer, BaseHTTPRequestHandler


class Request(BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(b'{"result": "server test"}')

    def do_POST(self):
        self.send_response(400)
        self.send_header('Content-type', 'application/json')
        self.end_headers()
        self.wfile.write(b'{"result": "server error"}')


def run_server():
    server = HTTPServer(('localhost', 8888), Request)
    server.serve_forever()


class TestClient(TestCase):
    @classmethod
    def setUpClass(cls):
        server = threading.Thread(target=run_server)
        server.setDaemon(True)
        server.start()

    def test_init(self):
        conf = Config()
        try:
            Client(conf)
        except Exception as e:
            self.assertIsInstance(e, TeaException)
        try:
            Client(None)
        except Exception as e:
            self.assertIsInstance(e, TeaException)
            self.assertEqual(
                "'config' can not be unset",
                e.message
            )

        conf = Config(
            access_key_id='access_key_id',
            security_token='security_token',
            protocol='protocol',
            region_id='region_id',
            read_timeout=1000,
            connect_timeout=5000,
            http_proxy='http_proxy',
            https_proxy='https_proxy',
            endpoint='endpoint',
            no_proxy='no_proxy',
            max_idle_conns=1,
            network='network',
            user_agent='user_agent',
            suffix='suffix',
            endpoint_type='endpoint_type',
            open_platform_endpoint='open_platform_endpoint',
            type='type',
        )
        conf.access_key_secret = 'access_key_secret'
        client = Client(conf)
        self.assertIsNotNone(client)

    def test_do_request(self):
        conf = Config(
            access_key_id='access_key_id',
            security_token='security_token',
            protocol='http',
            region_id='region_id',
            read_timeout=1000,
            connect_timeout=5000,
            endpoint='127.0.0.1:8888',
            max_idle_conns=1
        )
        conf.access_key_secret = 'access_key_secret'
        runtime = RuntimeOptions(
            autoretry=False,
            max_attempts=2
        )
        client = Client(conf)
        res = client.do_request(
            action='action',
            protocol='http',
            method='GET',
            version='version',
            auth_type='auth_type',
            query={},
            body={},
            runtime=runtime
        )
        self.assertEqual({'result': 'server test'}, res)
        try:
            client.do_request(
                action='action',
                protocol='http',
                method='POST',
                version='version',
                auth_type='auth_type',
                query={},
                body={},
                runtime=runtime
            )
            assert False
        except Exception as e:
            self.assertIsInstance(e, UnretryableException)

    def test_model(self):
        conf = Config(
            access_key_id='access_key_id',
            access_key_secret='access_key_secret',
            protocol='http',
            endpoint='127.0.0.1:8888'
        )
        conf.validate()
        conf = Config(
            access_key_id='access_key_id',
            access_key_secret='access_key_secret',
            protocol='http',
            region_id=None,
            endpoint='127.0.0.1:8888',
            network=None,
            suffix=None
        )
        self.assertIsInstance(conf, Config)
        conf.validate()
        conf.to_map()
        conf.from_map({})

    def test_default_any(self):
        self.assertEqual('test', Client.default_any('test', 'test1'))
        self.assertEqual('test1', Client.default_any(None, 'test1'))
