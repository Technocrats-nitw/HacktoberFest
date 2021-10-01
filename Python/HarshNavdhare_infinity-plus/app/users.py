import os
from typing import Optional

from fastapi import Depends, Request
from fastapi_users.manager import BaseUserManager
from fastapi_users.fastapi_users import FastAPIUsers
from fastapi_users.authentication.jwt import JWTAuthentication
from fastapi_users_db_mongodb import MongoDBUserDatabase

from app.db import get_user_db
from app.models import User, UserCreate, UserDB, UserUpdate

SECRET = os.getenv('SECRET', "")


class UserManager(BaseUserManager[UserCreate, UserDB]):
    user_db_model = UserDB
    reset_password_token_secret = SECRET
    verification_token_secret = SECRET

    async def on_after_register(self,
                                user: UserDB,
                                request: Optional[Request] = None):
        print(f"User {user.id} has registered.")

    async def on_after_forgot_password(self,
                                       user: UserDB,
                                       token: str,
                                       request: Optional[Request] = None):
        print(
            f"User {user.id} has forgot their password. Reset token: {token}")

    async def after_verification_request(self,
                                         user: UserDB,
                                         token: str,
                                         request: Optional[Request] = None):
        print(
            f"Verification requested for user {user.id}. Verification token: {token}"
        )


def get_user_manager(user_db: MongoDBUserDatabase = Depends(get_user_db)):
    yield UserManager(user_db)


jwt_authentication = JWTAuthentication(secret=SECRET,
                                       lifetime_seconds=3600,
                                       tokenUrl="auth/jwt/login")

fastapi_users = FastAPIUsers(
    get_user_manager,
    [jwt_authentication],
    User,
    UserCreate,
    UserUpdate,
    UserDB,
)

current_active_user = fastapi_users.current_user(active=True)