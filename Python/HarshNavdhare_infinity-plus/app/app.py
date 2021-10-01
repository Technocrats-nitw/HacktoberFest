from fastapi import Depends, FastAPI

from app.models import UserDB
from app.users import current_active_user, fastapi_users, jwt_authentication

auth_url = '/auth'
app = FastAPI()

app.include_router(fastapi_users.get_auth_router(jwt_authentication),
                   prefix=f"{auth_url}/jwt",
                   tags=["auth"])
app.include_router(fastapi_users.get_register_router(),
                   prefix=auth_url,
                   tags=["auth"])
app.include_router(
    fastapi_users.get_reset_password_router(),
    prefix=auth_url,
    tags=["auth"],
)
app.include_router(
    fastapi_users.get_verify_router(),
    prefix=auth_url,
    tags=["auth"],
)
app.include_router(fastapi_users.get_users_router(),
                   prefix="/users",
                   tags=["users"])


@app.get("/authenticated-route")
async def authenticated_route(user: UserDB = Depends(current_active_user)):
    return {"message": f"Hello {user.phone}!"}
