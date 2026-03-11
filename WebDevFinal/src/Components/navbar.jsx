import { Link, Outlet } from "react-router-dom";
import "../App.css"
import logo from '/Images/logo.png'
import './navbar.css'


export function NavBar() {
  return (
    <>
      <div className = "NavBar">
        <img src={logo} className="NavBarLogo" alt="Logo" />  
          <Link to = "/">
            <button className = "NavButtons"> Home </button>
          </Link>
          <Link to="/members">
            <button className = "NavButtons"> Members </button>
          </Link>
          <Link to="/tasks">
            <button className = "NavButtons"> Tasks </button>
          </Link>
        <Outlet />
      </div> 
    </>
  );
}