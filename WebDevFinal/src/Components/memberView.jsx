import React, { useState } from 'react';
import './memberView.css';

// Modal used for SINGLE MEMBER VIEW (shows name, department, and their tasks)
const Modal = ({ isOpen, onClose, member }) => {
  if (!isOpen) return null;

  return (
    <div className="singMemberView">
      <div className="memberDetails">
        <h1> {member.firstname} {member.lastname} </h1>
        <p> <u> Role</u>: {member.department}</p>
        <p> This player is working on: </p>
        <ul>
          {member.tasks && member.tasks.length > 0 ? (
            member.tasks.map((task, index) => (
              <p>• {task.content}</p>
            ))
          ) : (
            <li>No tasks assigned.</li>
          )}
        </ul>
        <button onClick={onClose}>Close</button>
      </div>
    </div>
  );
};

const MembersBox = ({ members, onDelete }) => {
  const [modalOpen, setModalOpen] = useState(false);
  const [selectedMember, setSelectedMember] = useState(null);

  const openModal = (member) => {
    setSelectedMember(member);
    setModalOpen(true);
  };

  const closeModal = () => {
    setModalOpen(false);
    setSelectedMember(null);
  };

  const handleDelete = (id) => {
    onDelete(id);
  };

  // Sort members by ID in ascending order
  const IDorder = [...members].sort((a, b) => a.id - b.id);

  return (
    <div className="memberBox">
      {IDorder.length === 0 ? (
        <p>No members found.</p>
      ) : (
        IDorder.map((member) => (
          <div className="card">
            <div className="horizontal">
              <span> {member.id}. </span>
              <span className="username" onClick={() => openModal(member)}>
                <b>{member.firstname} {member.lastname}</b>
              </span>
              <button onClick={() => handleDelete(member.id)}>X</button>
            </div>
            <p>{member.department}</p>
          </div>
        ))
      )}
      <Modal isOpen={modalOpen} onClose={closeModal} member={selectedMember} />
    </div>
  );
};

export default MembersBox;
