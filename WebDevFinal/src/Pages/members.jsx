import React, { useState, useEffect } from 'react';
import '../App.css';
import './members.css';
import MembersBox from '../Components/memberView';
import { useDispatch, useSelector } from 'react-redux';
import { fetchEmployees, addEmployee, deleteEmployee } from '../Store/employeesSlice';

export function Members() {
  const dispatch = useDispatch();
  const members = useSelector((state) => state.employees);

  //Gets tasks from store
  useEffect(() => {
    dispatch(fetchEmployees());
  }, [dispatch]);

  //Deletes task from store
  const deleteMember = (id) => {
    dispatch(deleteEmployee(id));
  };

  //Prompts user to add a member then saves info in the STORE
  const addMember = async () => {
    const firstname = window.prompt("Enter FIRST name:");
    const lastname = window.prompt("Enter LAST name:");
    let role = window.prompt("OPTIONAL - Enter role:");

    if (!role) {
      role = "*Department is TBD*";
    }

    if (firstname && lastname || role) {
      const newMember = { firstname, lastname, department: role }; // Adjust fields based on backend requirements
      await dispatch(addEmployee(newMember));
    } else {
      alert("Both Username and Role type are required.");
    }
  };

  return (
    <>
      <div className="MembersPage">
        <h1 className="membersTitle">Meet the Members!</h1>
        <div className="membersAboutBox">
          <b>
            Below, you will see a lineup for <i>"<u>The Hangout</u>"</i> Minecraft server! Each name shown below is displayed with their role in the server.
            Click on the name of the member for a more detailed view!
            <br /> <br />
            Hit the <i>ADD MEMBER</i> button below to join us!
          </b>
        </div>
        <button id="add" onClick={addMember}>ADD MEMBER</button>
        <div className="allMembers">
          <MembersBox members={members} onDelete={deleteMember} />
        </div>
      </div>
    </>
  );
}

export default Members;
