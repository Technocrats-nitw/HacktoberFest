import os

import motor.motor_asyncio
from fastapi_users_db_mongodb import MongoDBUserDatabase

from .models import UserDB

DATABASE_URL = os.getenv('DATABASE_URL')
DB_NAME = 'users'
COLLECTION_NAME = 'creds'
client = motor.motor_asyncio.AsyncIOMotorClient(DATABASE_URL,
                                                uuidRepresentation="standard")
db = client[DB_NAME]
collection = db[COLLECTION_NAME]


def get_user_db():
    yield MongoDBUserDatabase(UserDB, collection)
