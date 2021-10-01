from typing import Optional
from fastapi_users import models
from pydantic import EmailStr, Field
from typing import Optional


class User(models.BaseUser):
    """Base User model."""
    phone: str = Field(..., min_length=10, max_length=10, regex=r'^\d{10}$')
    email: Optional[EmailStr]


class UserCreate(models.BaseUserCreate):
    phone: str = Field(..., min_length=10, max_length=10)
    email: Optional[EmailStr]


class UserUpdate(models.BaseUserUpdate):
    phone: str = Field(..., min_length=10, max_length=10)
    email: Optional[EmailStr]


class UserDB(models.BaseUserDB):
    phone: str = Field(..., min_length=10, max_length=10)
    email: Optional[EmailStr]
    hashed_password: str

    class Config:
        orm_mode = True